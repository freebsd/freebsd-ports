# $FreeBSD$

PORTNAME=	libpgf
PORTVERSION=	6.14.12
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-latest/ \
		SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Progressive Graphics Format (PGF) library

LICENSE=	LGPL21

USES=		dos2unix libtool
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	configure.ac
AUTOMAKE_ARGS=	--add-missing --copy
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	@cd ${WRKSRC}; ${TOUCH} NEWS AUTHORS

.include <bsd.port.mk>
