# $FreeBSD$

PORTNAME=	shtk
PORTVERSION=	1.6
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/jmmv

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_DEFAULT=TEST

.include <bsd.port.options.mk>

MAKE_FLAGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
.if empty(PORT_OPTIONS:MDOCS)
MAKE_FLAGS+=	doc_DATA=
.endif
.if empty(PORT_OPTIONS:MTEST)
PLIST_SUB+=	TEST="@comment "
.else
PLIST_SUB+=	TEST=
.endif

post-install:
.if empty(PORT_OPTIONS:MTEST)
	@${RM} -r ${STAGEDIR}${PREFIX}/tests
.endif

.include <bsd.port.mk>
