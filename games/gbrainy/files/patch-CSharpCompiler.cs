--- src/Core/Libraries/CSharpCompiler.cs.orig	2012-05-23 16:50:05.000000000 +0800
+++ src/Core/Libraries/CSharpCompiler.cs	2012-05-24 08:50:05.000000000 +0800
@@ -44,10 +44,7 @@
 
 		public CSharpCompiler ()
 		{
-			CompilerSettings settings = new CompilerSettings ();
-			Report report = new Report (new NullReportPrinter ());
-
-			evaluator = new Evaluator (settings, report);
+			evaluator = new Evaluator (new CompilerContext (new CompilerSettings (), new NullReportPrinter ()));
 		}
 
 		public void EvaluateCode (string code)
