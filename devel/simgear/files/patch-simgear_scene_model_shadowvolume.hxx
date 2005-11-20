--- simgear/scene/model/shadowvolume.hxx.orig	Sun Nov 20 05:25:21 2005
+++ simgear/scene/model/shadowvolume.hxx	Sun Nov 20 05:29:56 2005
@@ -60,6 +60,14 @@
 	void endOfFrame(void);
 	static int ACpostTravCB( ssgEntity *entity, int traversal_mask );
 
+	bool	shadowsDebug_enabled;
+	bool	shadowsAC_transp_enabled;
+	bool	use_alpha;
+
+	sgVec3 sunPos;
+	int frameNumber;
+	int lastTraverseTreeFrame;
+	sgMat4 CameraViewM;
 private:
 
 	class ShadowCaster
@@ -126,16 +134,10 @@
 	void cull ( ssgBranch *b, sgFrustum *f, sgMat4 m, int test_needed );
 
 	bool	shadows_enabled;
-	bool	shadowsAC_enabled, shadowsAI_enabled, shadowsTO_enabled, shadowsDebug_enabled;
-	bool	shadowsAC_transp_enabled;
-	bool	use_alpha;
+	bool	shadowsAC_enabled, shadowsAI_enabled, shadowsTO_enabled;
 	bool	canDoAlpha, canDoStencil;
 	SGPropertyNode *sim_rendering;
 
-	sgVec3 sunPos;
-	int frameNumber;
-	int lastTraverseTreeFrame;
-	sgMat4 CameraViewM;
 	double	sun_angle;
 	SceneryObject_map sceneryObjects;
 	ssgBranch *ssg_root;
