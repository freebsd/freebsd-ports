# Created by: Jerry Hicks
# $FreeBSD$

PORTNAME=	bison
PORTVERSION=	2.7.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A parser generator from FSF, (mostly) compatible with Yacc

BUILD_DEPENDS=	m4>=1.4.16,1:${PORTSDIR}/devel/m4
RUN_DEPENDS=	m4>=1.4.16,1:${PORTSDIR}/devel/m4

OPTIONS_DEFINE=	EXAMPLES NLS

USES=		charsetfix perl5
USE_XZ=		yes
USE_PERL5=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-yacc

MAN1=		bison.1
INFO=		bison

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/bison.info*
	@${REINPLACE_CMD} 's/MANS = yacc.1/MANS =/' ${WRKSRC}/doc/Makefile.in
.if ! ${PORT_OPTIONS:MNLS}
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
