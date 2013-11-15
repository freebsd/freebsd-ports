--- intern/itasc/kdl/tree.hpp.orig	2012-12-15 12:15:05.000000000 +0100
+++ intern/itasc/kdl/tree.hpp	2013-11-13 12:06:00.000000000 +0100
@@ -60,13 +60,13 @@
     public:
         Segment segment;
         unsigned int q_nr;
-        SegmentMap::const_iterator  parent;
+        std::pair<const std::string, TreeElement> const *parent;
         std::vector<SegmentMap::const_iterator > children;
         TreeElement(const Segment& segment_in,const SegmentMap::const_iterator& parent_in,unsigned int q_nr_in)
         {
 			q_nr=q_nr_in;
             segment=segment_in;
-            parent=parent_in;
+            parent=&*parent_in;
         };
         static TreeElement Root()
         {
--- intern/itasc/kdl/treefksolverpos_recursive.cpp.orig	2011-10-23 20:38:16.000000000 +0200
+++ intern/itasc/kdl/treefksolverpos_recursive.cpp	2013-11-13 14:43:21.000000000 +0100
@@ -45,12 +45,12 @@
         else if(baseit == tree.getSegments().end()) //if the base segment name is not found
          	return -3;
         else{
-			p_out = recursiveFk(q_in, it, baseit);	
+			p_out = recursiveFk(q_in, &*it, &*baseit);	
         	return 0;        	
         }
     }
 
-	Frame TreeFkSolverPos_recursive::recursiveFk(const JntArray& q_in, const SegmentMap::const_iterator& it, const SegmentMap::const_iterator& baseit)
+	Frame TreeFkSolverPos_recursive::recursiveFk(const JntArray& q_in, std::pair<const std::string, KDL::TreeElement> const *it, std::pair<const std::string, KDL::TreeElement> const *baseit)
 	{
 		//gets the frame for the current element (segment)
 		const TreeElement& currentElement = it->second;
@@ -60,8 +60,7 @@
 		}
 		else{
 			Frame currentFrame = currentElement.segment.pose(((JntArray&)q_in)(currentElement.q_nr));
-			SegmentMap::const_iterator parentIt = currentElement.parent;
-			return recursiveFk(q_in, parentIt, baseit) * currentFrame;
+			return recursiveFk(q_in, currentElement.parent, baseit) * currentFrame;
 		}
 	}
 
--- intern/itasc/kdl/treefksolverpos_recursive.hpp.orig	2009-07-14 17:36:21.000000000 +0200
+++ intern/itasc/kdl/treefksolverpos_recursive.hpp	2013-11-13 14:48:02.000000000 +0100
@@ -45,7 +45,7 @@
     private:
         const Tree tree;
         
-        Frame recursiveFk(const JntArray& q_in, const SegmentMap::const_iterator& it, const SegmentMap::const_iterator& baseit);
+        Frame recursiveFk(const JntArray& q_in, std::pair<const std::string, KDL::TreeElement> const *it, std::pair<const std::string, KDL::TreeElement> const *baseit);
     };
 
 }
--- intern/itasc/kdl/treejnttojacsolver.cpp.orig	2011-10-23 20:38:16.000000000 +0200
+++ intern/itasc/kdl/treejnttojacsolver.cpp	2013-11-13 15:04:38.000000000 +0100
@@ -28,16 +28,16 @@
         return -1;
 
     //Lets search the tree-element
-    SegmentMap::const_iterator it = tree.getSegments().find(segmentname);
+    std::pair<const std::string, KDL::TreeElement> const *it = &*tree.getSegments().find(segmentname);
 
     //If segmentname is not inside the tree, back out:
-    if (it == tree.getSegments().end())
+    if (it == &*tree.getSegments().end())
         return -2;
 
     //Let's make the jacobian zero:
     SetToZero(jac);
 
-    SegmentMap::const_iterator root = tree.getSegments().find("root");
+    std::pair<const std::string, KDL::TreeElement> const *root = &*tree.getSegments().find("root");
 
     Frame T_total = Frame::Identity();
 	Frame T_local, T_joint;
--- intern/itasc/Armature.cpp.orig	2013-03-18 12:44:56.000000000 +0100
+++ intern/itasc/Armature.cpp	2013-11-13 14:21:32.000000000 +0100
@@ -402,7 +402,7 @@
 	m_armlength = 0.0;
 	for (i=0; i<m_neffector; i++) {
 		length = 0.0;
-		KDL::SegmentMap::const_iterator sit = m_tree.getSegment(m_effectors[i].name);
+		std::pair<const std::string, KDL::TreeElement> const *sit = &*m_tree.getSegment(m_effectors[i].name);
 		while (sit->first != "root") {
 			Frame tip = sit->second.segment.pose(m_qKdl(sit->second.q_nr));
 			length += tip.p.Norm();
