# Ports collection makefile for:  ZendStudio
# Date created:			  24 February 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	ZendStudio
PORTVERSION=	3.5.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}

MAINTAINER=	tux@pinguru.net
COMMENT=	A PHP IDE

NO_BUILD=	yes
RESTRICTED=	"Redistribution is not permitted"

USE_LINUX=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTFILES})
ECHO_MSG=	/usr/bin/printf
IGNORE=		:\nBecause of licensing restrictions, you must fetch the source distribution\nmanually. Please access http://www.zend.com/store/products/zend-studio.php\nwith a web browser and follow the \"Free Evaluation\" link.\nYou have to register for using ZendStudio.\nAfter download the file, place it into ${DISTDIR}\n
.endif

dd:
		@${ECHO} ${DISTNAME}

pre-install:
	@if [ "`/sbin/mount | ${GREP} ^linprocfs`" = "" ]; \
		then \
		${ECHO_MSG} "For installing and running ZendStudio " ; \
		${ECHO_MSG} "you have to have LINPROCFS mounted before" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "You may do it by following set of commands:" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "# kldload linprocfs" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "and" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "# mount_linprocfs  linproc /compat/linux/proc" ; \
		${ECHO_MSG} "" ; \
		exit 1 ; \
	fi

do-install:
	${WRKSRC}/${DISTNAME}.bin

post-install:
	${LN} -s ${PREFIX}/Zend/bin/ZDE ${PREFIX}/bin/ZDE

.include <bsd.port.post.mk>
