--- src/appleseed/renderer/modeling/bsdf/glossybrdf.cpp.orig	2016-06-01 14:42:16 UTC
+++ src/appleseed/renderer/modeling/bsdf/glossybrdf.cpp
@@ -177,9 +177,10 @@ namespace
 
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
@@ -188,9 +189,10 @@ namespace
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
@@ -236,8 +238,9 @@ namespace
 
             if (m_mdf == GGX)
             {
+                GGXMDF<double> ggxmdf;
                 return MicrofacetBRDFHelper<double>::evaluate(
-                    GGXMDF<double>(),
+                    ggxmdf,
                     alpha_x,
                     alpha_y,
                     shading_basis,
@@ -250,8 +253,9 @@ namespace
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
@@ -293,8 +297,9 @@ namespace
 
             if (m_mdf == GGX)
             {
+                GGXMDF<double> ggxmdf;
                 return MicrofacetBRDFHelper<double>::pdf(
-                    GGXMDF<double>(),
+                    ggxmdf,
                     alpha_x,
                     alpha_y,
                     shading_basis,
@@ -303,8 +308,9 @@ namespace
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
