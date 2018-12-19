# $FreeBSD$

PORTNAME=	evdev-proto
PORTVERSION=	4.19
CATEGORIES=	devel
MASTER_SITES=	https://github.com/torvalds/linux/raw/v${PORTVERSION}/include/uapi/linux/
DISTFILES=	input.h input-event-codes.h uinput.h
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Input event device header files

LICENSE=	GPLv2

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${DISTFILES:S|^|include/linux/|}

do-extract:
	@${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}
.endfor

post-patch:
	@${REINPLACE_CMD} -i '' -E -e \
		's/__u([[:digit:]]+)/uint\1_t/g ; \
		s/__s([[:digit:]]+)/int\1_t/g ; \
		/# *include/ s|<sys/ioctl.h>|<sys/ioccom.h>| ; \
		/# *include[[:space:]]+<linux\/types.h>/d ; \
		/EVIOC(RMFF|GRAB|REVOKE)/ s/_IOW(.*), *int/_IOWINT\1/ ; \
		/EVIOCGKEYCODE/ s/_IOR/_IOWR/ ; \
		/EVIOCGMASK/ s/_IOR/_IOW/ ; \
		/EVIOCGMTSLOTS/ s/_IOC_READ/IOC_INOUT/ ; \
		/#define/ s/_IOC_READ/IOC_OUT/ ; \
		/#define/ s/_IOC_WRITE/IOC_IN/ ; \
		s/[[:space:]]+__user[[:space:]]+/ / ; \
		/__USE_TIME_BITS64/ s|^#if (.*)$$|#if 1 /* \1 */|' \
		${WRKSRC}/input.h
	@${REINPLACE_CMD} -i '' -E -e \
		's/__u([[:digit:]]+)/uint\1_t/g ; \
		s/__s([[:digit:]]+)/int\1_t/g ; \
		/# *include/s|<linux/types.h>|<sys/types.h>| ; \
		/#define/ s/_IOW(.*), *int/_IOWINT\1/ ; \
		/#define/ s/_IOW(.*), *char\*/_IO\1/ ; \
		/#define/ s/_IOC_READ/IOC_OUT/' \
		${WRKSRC}/uinput.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/linux/
.for i in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} \
		${STAGEDIR}${PREFIX}/include/linux/
.endfor

.include <bsd.port.mk>
