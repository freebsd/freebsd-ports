PORTNAME=	uzap
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	LOCAL/joerg
DISTNAME=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Visual binary file editor

# Has been posted to alt.sources in 1989
# http://www.megalextoria.com/usenet-archive/news097f1/b120/alt/sources/00000521.html
# Converted from NO_CDROM
LICENSE=	uzap
LICENSE_NAME=	uzap
LICENSE_TEXT=	This software may not be used to make a profit in any way.
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		ncurses

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/uzap share/man/man1/uzap.1.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
