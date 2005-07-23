# Ports collection makefile for:  ZendStudio
# Date created:			  24 February 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	ZendStudio
PORTVERSION=	3.5.2
PORTREVISION=	2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
MASTER_SITES=	http://www.zend.com/store/products/zend-studio.php
MAINTAINER=	tux@pinguru.net
COMMENT=	A PHP IDE

NO_BUILD=	yes
RESTRICTED=	"Redistribution is not permitted"
NO_PACKAGES=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}
USE_LINUX=	yes
USE_X_PREFIX=	yes

BROKEN=		Unfetchable
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
#ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Because of licensing restrictions, you must fetch the distribution manually.\n\
Please visit ${MASTER_SITES}\n\
and follow the \"Free Evaluation\" link.\n\
You have to register for using ZendStudio.\n\
After downloading the Client-package \"Linux glibc2.1\", place it into ${DISTDIR}.\n
.endif

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
# This is missing a "${BRANDELF} -t Linux <executables>"

.include <bsd.port.post.mk>
