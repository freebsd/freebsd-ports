--- src/utils/bullet/BulletSoftBody/btSoftBody.h.orig	2010-02-18 01:52:17.000000000 +0300
+++ src/utils/bullet/BulletSoftBody/btSoftBody.h	2013-06-18 05:58:55.243113542 +0400
@@ -182,6 +182,7 @@
 		btScalar				m_kAST;			// Area/Angular stiffness coefficient [0,1]
 		btScalar				m_kVST;			// Volume stiffness coefficient [0,1]
 		int						m_flags;		// Flags
+		Material() {}
 	};
 
 	/* Feature		*/ 
@@ -201,6 +202,7 @@
 		btScalar				m_area;			// Area
 		btDbvtNode*				m_leaf;			// Leaf data
 		int						m_battach:1;	// Attached
+		Node() {}
 	};
 	/* Link			*/ 
 	struct	Link : Feature
@@ -212,6 +214,7 @@
 		btScalar				m_c1;			// rl^2
 		btScalar				m_c2;			// |gradient|^2/c0
 		btVector3				m_c3;			// gradient
+		Link() {}
 	};
 	/* Face			*/ 
 	struct	Face : Feature
@@ -220,6 +223,7 @@
 		btVector3				m_normal;		// Normal
 		btScalar				m_ra;			// Rest area
 		btDbvtNode*				m_leaf;			// Leaf data
+		Face() {}
 	};
 	/* Tetra		*/ 
 	struct	Tetra : Feature
@@ -230,6 +234,7 @@
 		btVector3				m_c0[4];		// gradients
 		btScalar				m_c1;			// (4*kVST)/(im0+im1+im2+im3)
 		btScalar				m_c2;			// m_c1/sum(|g0..3|^2)
+		Tetra() {}
 	};
 	/* RContact		*/ 
 	struct	RContact
@@ -271,6 +276,7 @@
 		int						m_rank;			// Rank
 		Node*					m_nodes[4];		// Nodes
 		btScalar				m_coords[4];	// Coordinates
+		Note() {}
 	};	
 	/* Pose			*/ 
 	struct	Pose
