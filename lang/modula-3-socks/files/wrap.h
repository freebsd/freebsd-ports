#include "socksconf.h"

#if defined(HPSOCKS) /* { */
  #define accept        Raccept
  #define bind          Rxbind
  #define close         Rclose
  #define connect       Rconnect
  #define dup           Rdup
  #define dup2          Rdup2
  #define gethostbyaddr Rgethostbyaddr
  #define gethostbyname Rgethostbyname
  #define getpeername   Rgetpeername
  #define getsockname   Rgetsockname
  #define listen        Rlisten
  #define recv          Rrecv
  #define recvfrom      Rrecvfrom
  #define send          Rsend
  #define sendto        Rsendto
  #define shutdown      Rshutdown
  #define socket        Rsocket
#elif defined(SOCKS4) /* } { */
  #define accept        Raccept
  #define bind          Rbind
  #define connect       Rconnect
  #define getpeername   Rgetpeername
  #define getsockname   Rgetsockname
  #define listen        Rlisten
  #define select        Rselect
#elif defined(SOCKS5) /* } { */
  #define accept        SOCKSaccept
  #define bind          SOCKSbind
  #define close         SOCKSclose
  #define connect       SOCKSconnect
  #define dup           SOCKSdup
  #define dup2          SOCKSdup2
  #define fclose        SOCKSfclose
  #define gethostbyname SOCKSgethostbyname
  #define getpeername   SOCKSgetpeername
  #define getsockname   SOCKSgetsockname
  #define listen        SOCKSlisten
  #define read          SOCKSread
  #define recv          SOCKSrecv
  #define recvfrom      SOCKSrecvfrom
  #define rresvport     SOCKSrresvport
  #define select        SOCKSselect
  #define send          SOCKSsend
  #define sendto        SOCKSsendto
  #define shutdown      SOCKSshutdown
  #define write         SOCKSwrite
#endif /* } */

extern int RT0u__inCritical;
#define ENTER_CRITICAL RT0u__inCritical++
#define EXIT_CRITICAL  RT0u__inCritical--

static char RTHeapDepC__c;
#define MAKE_READABLE(x) \
    if ((int)x) { RTHeapDepC__c = *(char*)(x); }

#define MAKE_WRITABLE(x) \
    if ((int)x) { *(char*)(x) = RTHeapDepC__c = *(char*)(x); }
