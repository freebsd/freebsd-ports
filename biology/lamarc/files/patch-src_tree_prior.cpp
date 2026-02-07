--- src/tree/prior.cpp.orig	2025-05-18 23:58:05 UTC
+++ src/tree/prior.cpp
@@ -85,12 +85,12 @@ std::pair<double, double> Prior::RandomDraw() const
         case LINEAR:
             newparam = rnd.Float() * (m_upperbound - m_lowerbound) + m_lowerbound;
             newlnparam = log(newparam);
-            return std::make_pair<double, double>(newparam, newlnparam);
+            return std::make_pair(newparam, newlnparam);
             break;
         case LOGARITHMIC:
             newlnparam = rnd.Float() * (m_lnupper - m_lnlower) + m_lnlower;
             newparam = exp(newlnparam);
-            return std::make_pair<double, double>(newparam, newlnparam);
+            return std::make_pair(newparam, newlnparam);
             break;
     }
     string e = "Unknown prior type " + ToString(m_priortype) +
