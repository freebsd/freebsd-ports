--- src/appleseed/renderer/modeling/bsdf/metalbrdf.cpp.orig	2016-06-02 10:22:05 UTC
+++ src/appleseed/renderer/modeling/bsdf/metalbrdf.cpp
@@ -201,9 +201,10 @@ namespace
 
             if (m_mdf == GGX)
             {
+                GGXMDF<double> ggxmdf;
                 MicrofacetBRDFHelper<double>::sample(
                     sampling_context,
-                    GGXMDF<double>(),
+                    ggxmdf,
                     alpha_x,
                     alpha_y,
                     f,
@@ -212,9 +213,10 @@ namespace
             }
             else
             {
+                BeckmannMDF<double> beckmannmdf;
                 MicrofacetBRDFHelper<double>::sample(
                     sampling_context,
-                    BeckmannMDF<double>(),
+                    beckmannmdf,
                     alpha_x,
                     alpha_y,
                     f,
@@ -260,8 +262,9 @@ namespace
 
             if (m_mdf == GGX)
             {
+                GGXMDF<double> ggxmdf;
                 return MicrofacetBRDFHelper<double>::evaluate(
-                    GGXMDF<double>(),
+                    ggxmdf,
                     alpha_x,
                     alpha_y,
                     shading_basis,
@@ -274,8 +277,9 @@ namespace
             }
             else
             {
+                BeckmannMDF<double> beckmannmdf;
                 return MicrofacetBRDFHelper<double>::evaluate(
-                    BeckmannMDF<double>(),
+                    beckmannmdf,
                     alpha_x,
                     alpha_y,
                     shading_basis,
@@ -317,8 +321,9 @@ namespace
 
             if (m_mdf == GGX)
             {
+                GGXMDF<double> ggxmdf;
                 return MicrofacetBRDFHelper<double>::pdf(
-                    GGXMDF<double>(),
+                    ggxmdf,
                     alpha_x,
                     alpha_y,
                     shading_basis,
@@ -327,8 +332,9 @@ namespace
             }
             else
             {
+                BeckmannMDF<double> beckmannmdf;
                 return MicrofacetBRDFHelper<double>::pdf(
-                    BeckmannMDF<double>(),
+                    beckmannmdf,
                     alpha_x,
                     alpha_y,
                     shading_basis,
