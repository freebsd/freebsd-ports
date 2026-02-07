PORTNAME=	pcc
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc-releases/ \
		http://pcc.ludd.ltu.se/ftp/pub/pcc-releases/ \
		ftp://226.net120.skekraft.net/pcc-releases/

MAINTAINER=	joel@FreeBSD.org
COMMENT=	Portable C Compiler
WWW=		http://pcc.ludd.ltu.se/

LICENSE=	BSD2CLAUSE BSD3CLAUSE BSDCOMPATIBLE
LICENSE_COMB=	multi
LICENSE_NAME_BSDCOMPATIBLE=	BSD-style compatible licenses
LICENSE_TEXT_BSDCOMPATIBLE=	The license: BSDCOMPATIBLE (${LICENSE_NAME_BSDCOMPATIBLE}), \
				please read from the web: http://pcc.ludd.ltu.se/licenses/
LICENSE_PERMS_BSDCOMPATIBLE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	i386 amd64

RUN_DEPENDS=	pcc-libs>=${PORTVERSION}:devel/pcc-libs

USES=		gmake tar:tgz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	YACC=${YACC}

PLIST_FILES=	bin/pcc bin/pcpp \
		libexec/ccom libexec/cxxcom libexec/cpp \
		share/man/man1/ccom.1.gz share/man/man1/cpp.1.gz \
		share/man/man1/pcc.1.gz

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	THREADS
OPTIONS_DEFAULT=	THREADS
THREADS_DESC=	Enable Thread-local storage (TLS)
THREADS_CONFIGURE_ENABLE=	tls

.include <bsd.port.pre.mk>

post-patch:
	# Don't make empty directories, which created by devel/pcc-libs port
	@${REINPLACE_CMD} -e '/mkdir -p.*PCC.*DIR/d' \
		${WRKSRC}/cc/cc/Makefile.in
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -e '/targmach=amd64/s/x86_64/amd64/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,\" MKS(TARGOSVER),${OSREL:R}\",' \
		${WRKSRC}/os/freebsd/ccconfig.h
.endif

.include <bsd.port.post.mk>
