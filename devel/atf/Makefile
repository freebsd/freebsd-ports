# $FreeBSD$

PORTNAME=	atf
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	namor@hemio.de
COMMENT=	Automated Testing Framework

LICENSE=	BSD

USE_LDCONFIG=	yes

PROJECTHOST=	kyua

MAN1=		atf-check.1 \
		atf-sh.1 \
		atf-test-program.1
MAN3=		atf-c-api.3 \
		atf-c++-api.3 \
		atf-sh-api.3
MAN4=		atf-test-case.4

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	TOOLS
OPTIONS_DEFAULT=TOOLS
TOOLS_DESC=	Enable deprecated tools

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000021
IGNORE=	is already in the base system
.endif

.if ${PORT_OPTIONS:MTOOLS}
CONFIGURE_ARGS+=	--enable-tools
PLIST_SUB+=		TOOLS=""
MAN1+=			atf-config.1 \
			atf-report.1 \
			atf-run.1 \
			atf-version.1
MAN5+=			atf-formats.5
MAN7+=			atf.7
.else
PLIST_SUB+=		TOOLS="@comment "
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's|install-docDATA[^:]||' ${WRKSRC}/Makefile.in
.endif
.if empty(PORT_OPTIONS:MEXAMPLES)
	@${REINPLACE_CMD} -e 's|install-egDATA[^:]||' \
			  -e 's|install-cssDATA[^:]||' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|@atf_pkgconfigdir@|${PREFIX}/libdata/pkgconfig|' \
	  ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
