# Created by: Sergey A. Osokin <osa@FreeBSD.org.ru>
# $FreeBSD$

PORTNAME=	gigabase
PORTVERSION=	3.91
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION} \
		http://www.garret.ru/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-Relational Database Management System

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix gmake libtool
DOS2UNIX_FILES=	Makefile.in *.cpp *.h
USE_GCC=	any
USE_AUTOTOOLS=	libtoolize aclocal autoconf
USE_LDCONFIG=	yes

LDFLAGS+=	-pthread

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/GiST/Makefile

.include <bsd.port.mk>
