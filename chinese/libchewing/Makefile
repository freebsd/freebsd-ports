# Created by: Kuang-che Wu <kcwu@csie.org>
# $FreeBSD$

PORTNAME=	libchewing
PORTVERSION=	0.3.4
CATEGORIES=	chinese textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	The Chewing intelligent phonetic input method library

INFO=		libchewing

USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_PKGCONFIG=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_BZIP2=	yes

DATADIR=	${PREFIX}/share/chewing
PROJECTHOST=	chewing

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc: signal 6
.endif

.include <bsd.port.post.mk>
