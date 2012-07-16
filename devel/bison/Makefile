# Ports collection makefile for:  bison
# Date created:			  27 Mar 1999
# Whom:				  Jerry Hicks
#
# $FreeBSD$
#

PORTNAME=	bison
PORTVERSION=	2.5.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A parser generator from FSF, (mostly) compatible with Yacc

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_XZ=		yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-yacc

MAN1=		bison.1
INFO=		bison

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.ifdef USE_BISON
.error You have `USE_BISON' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/bison.info*
	@${REINPLACE_CMD} 's/MANS = yacc.1/MANS =/' ${WRKSRC}/doc/Makefile.in
.if empty(${PORT_OPTIONS:MNLS})
	@${REINPLACE_CMD} 's/ install-exec-local//' ${WRKSRC}/lib/Makefile.in
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	calc++

post-install:
	${MKDIR} ${EXAMPLESDIR}/calc++
	${INSTALL_DATA} ${WRKSRC}/examples/calc++/*.[chly]* \
		${EXAMPLESDIR}/calc++
.endif

.include <bsd.port.mk>
