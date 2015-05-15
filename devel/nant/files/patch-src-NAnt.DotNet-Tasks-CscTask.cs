Reference:	https://github.com/nant/nant/issues/91
Obtained from:	https://github.com/nant/nant/commit/69c8ee96493c5d953212397c8ca06c2392372ca4
		https://github.com/nant/nant/commit/4ad065d009b043996d4ce2d25ce5031d81c6ce60

--- src/NAnt.DotNet/Tasks/CscTask.cs.orig	2012-06-09 14:05:53 UTC
+++ src/NAnt.DotNet/Tasks/CscTask.cs
@@ -90,6 +90,7 @@ namespace NAnt.DotNet.Tasks {
         private string _langVersion;
 
         // framework configuration settings
+        private double _mcsSdk = 0;
         private bool _supportsDocGeneration = true;
         private bool _supportsPlatform;
         private bool _supportsLangVersion;
@@ -362,6 +363,21 @@ namespace NAnt.DotNet.Tasks {
 
         #endregion Public Instance Properties
 
+        #region Protected Instance Properties
+
+        /// <summary>
+        /// Gets or sets the mcs sdk version to apply to the new mcs compiler
+        /// for Mono 3.0+
+        /// </summary>
+        [FrameworkConfigurable("mcssdk")]
+        protected double McsSdk 
+        {
+            get { return _mcsSdk; }
+            set { _mcsSdk = value; }
+        }
+
+        #endregion Protected Instance Properties
+
         #region Override implementation of CompilerBase
 
         /// <summary>
@@ -378,6 +394,16 @@ namespace NAnt.DotNet.Tasks {
                 WriteOption(writer, "baseaddress", BaseAddress);
             }
 
+            // If mcs is the compiler and the specified McsSdk version is specified, append the new
+            // -sdk: option to the argument list.
+            if (PlatformHelper.IsMono) 
+            {
+                if (ExeName.Equals("mcs", StringComparison.InvariantCultureIgnoreCase) && _mcsSdk > 0) 
+                {
+                    WriteOption(writer, "sdk", _mcsSdk.ToString());
+                }
+            }
+
             // XML documentation
             if (DocFile != null) {
                 if (SupportsDocGeneration) {
