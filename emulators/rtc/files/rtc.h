#ifndef RTC_H
#define RTC_H


#define RTCIO_PIE_ON		_IO('p', 0x05)
#define RTCIO_IRQP_SET		_IO('p', 0x0c)

#ifndef M_WAITOK
#define M_WAITOK	0x0000
#endif

#endif /* RTC_H */

