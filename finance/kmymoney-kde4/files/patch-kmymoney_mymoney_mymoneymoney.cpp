commit 77209f84a85360e98d2e805d412956a8f2a77db3
Author: Alex Merry <kde@randomguy3.me.uk>
Date:   Fri Feb 1 15:31:54 2013 +0000

    Fix build with GMP 5.1.0
    
    GMP 5.1.0 no longer has implicit conversions to mpz_class from mpq_class
    or mpf_class.  So we have to have an explicit conversion.
    
    BUG: 312481

diff --git a/kmymoney/mymoney/mymoneymoney.cpp b/kmymoney/mymoney/mymoneymoney.cpp
index aeed135..5de7fa9 100644
--- kmymoney/mymoney/mymoneymoney.cpp
+++ kmymoney/mymoney/mymoneymoney.cpp
@@ -158,7 +158,7 @@ QString MyMoneyMoney::formatMoney(const QString& currency, const int prec, bool
   // be much better than using KGlobal::locale()->formatMoney.
   bool bNegative = false;
   mpz_class left = value / static_cast<MyMoneyMoney>(convertDenominator(d)).valueRef().get_den();
-  mpz_class right = (valueRef() - mpq_class(left)) * denom;
+  mpz_class right = mpz_class((valueRef() - mpq_class(left)) * denom);
 
   if (right < 0) {
     right = -right;
