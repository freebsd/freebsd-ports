# New ports collection makefile for:	baudline
# Date created:				19 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	baudline
PORTVERSION=	0.97
CATEGORIES=	audio linux
MASTER_SITES=	http://www.baudline.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	baudline_${PORTVERSION:S/.p/pre/}_i686

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A real-time signal analysis tool and an offline time-frequency browser

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_X_PREFIX=	yes
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_BUILD=	yes
STRIP=

BRANDELF?=	/usr/bin/brandelf

RESTRICTED=	"author requests no distribution except from their site"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

.include <bsd.port.pre.mk>

LINPROCFS!=	/sbin/mount | ${GREP} linprocfs | ${AWK} '{print $1}'

pre-everything::
.if ${LINPROCFS}
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Check if linprocfs is running: YES"
.else
	@${ECHO_CMD} "-----------------------------------------------------------"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Baudline needs a running linprocfs, which is not"
	@${ECHO_CMD} "activated on your system. Please read the linprocfs\(5\)"
	@${ECHO_CMD} "manpage and add the following line to /etc/fstab:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "linproc /compat/linux/proc linprocfs rw 0 0"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "-----------------------------------------------------------"
	@${FALSE}
.endif

do-install:
	@${BRANDELF} -t Linux ${WRKSRC}/baudline
	@${INSTALL_PROGRAM} ${WRKSRC}/baudline ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README mailcap.txt mime.types.txt
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
