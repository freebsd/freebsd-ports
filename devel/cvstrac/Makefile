# Created by: Bruce M Simpson <bms@spc.org>
# $FreeBSD$

PORTNAME?=	cvstrac
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cvstrac.org/
DISTNAME=	cvstrac-${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT?=	Web-Based Bug And Patch-Set Tracking System For CVS

LICENSE=	GPLv2

USES=		gmake pkgconfig sqlite
MAKEFILE=	bsd-gcc.mk
MAKE_ARGS+=	BCC="${CC} ${CPPFLAGS}" TCC="${CC} ${CPPFLAGS}" \
		LIBSQLITE="${LDFLAGS}"
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	$$(pkg-config --cflags sqlite3)
LDFLAGS+=	$$(pkg-config --libs sqlite3) -lcrypt -lm

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
