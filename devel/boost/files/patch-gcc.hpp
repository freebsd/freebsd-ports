*** boost/config/compiler/gcc.hpp	2003/01/30 18:13:55	1.15
--- boost/config/compiler/gcc.hpp	2003/05/19 12:11:22	1.17
***************
*** 28,39 ****
  #     define BOOST_NO_OPERATORS_IN_NAMESPACE
  #   endif
  
  //
  // Threading support: Turn this on unconditionally here (except for
! // MinGW, where we can know for sure). It will get turned off again
  // later if no threading API is detected.
  //
! #if !defined(__MINGW32__) || defined(_MT)
  # define BOOST_HAS_THREADS
  #endif 
  
--- 28,43 ----
  #     define BOOST_NO_OPERATORS_IN_NAMESPACE
  #   endif
  
+ #ifndef __EXCEPTIONS
+ # define BOOST_NO_EXCEPTIONS
+ #endif
+ 
  //
  // Threading support: Turn this on unconditionally here (except for
! // those platforms where we can know for sure). It will get turned off again
  // later if no threading API is detected.
  //
! #if !defined(__MINGW32__) && !defined(__CYGWIN__) && !defined(linux) && !defined(__linux) && !defined(__linux__)
  # define BOOST_HAS_THREADS
  #endif 
  
***************
*** 58,68 ****
  #  error "Compiler not configured - please reconfigure"
  #endif
  //
! // last known and checked version is 3.2:
! #if (__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ > 2))
  #  if defined(BOOST_ASSERT_CONFIG)
  #     error "Unknown compiler version - please run the configure tests and report the results"
  #  else
  #     warning "Unknown compiler version - please run the configure tests and report the results"
  #  endif
  #endif
--- 62,73 ----
  #  error "Compiler not configured - please reconfigure"
  #endif
  //
! // last known and checked version is 3.3:
! #if (__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ > 3))
  #  if defined(BOOST_ASSERT_CONFIG)
  #     error "Unknown compiler version - please run the configure tests and report the results"
  #  else
  #     warning "Unknown compiler version - please run the configure tests and report the results"
  #  endif
  #endif
+ 
