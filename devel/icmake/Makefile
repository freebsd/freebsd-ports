PORTNAME=	icmake
PORTVERSION=	9.03.01
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Intelligent C-like Maker
WWW=		https://fbb-git.gitlab.io/icmake/

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed

USES=		compiler shebangfix
USE_GITLAB=	yes

WRKSRC_SUBDIR=	${PORTNAME}
PORTDOCS=	changelog.gz icmake.ps.gz
PORTEXAMPLES=	*

REINPLACE_ARGS=	-I ""

SHEBANG_FILES=	examples/* icm_install icm_prepare scripts/convert
SHEBANG_GLOB=	icm_bootstrap
SHEBANG_LANG=	icmake
icmake_OLD_CMD=	/usr/bin/icmake
icmake_CMD=	${LOCALBASE}/bin/icmake

GL_ACCOUNT=	fbb-git
GL_TAGNAME=	9b958b05ac462adf6cde394875964a8127599514

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|find|find .|g' \
		${WRKSRC}/icm_prepare
	@${REINPLACE_CMD} -e 's|tput clear|clear|g' \
		${WRKSRC}/changelog \
		${WRKSRC}/icmbuild/usage.c \
		${WRKSRC}/doc/icmconf.7 \
		${WRKSRC}/doc/manpage/icmbuild.yo \
		${WRKSRC}/doc/manpage/icmconf.yo \
		${WRKSRC}/doc/icmbuild.1
	@${REINPLACE_CMD} -e 's|sed|gsed|g' \
		${WRKSRC}/scripts/conversions \
		${WRKSRC}/scripts/convert
	@${REINPLACE_CMD} -e 's|"usr/bin"|"bin"| ; \
		s|"usr/share/icmake"|"share/icmake"| ; \
		s|"usr/share/man"|"share/man"| ; \
		s|"usr/lib/icmake"|"lib/icmake"| ; \
		s|"usr/share/doc/icmake"|"share/doc/icmake"| ; \
		s|"usr/share/doc/icmake-doc"|"share/examples/icmake"|' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e 's|cp -r|cp -R| ; \
		s|DOCDOCDIR}/icmake|DOCDIR}/icmake| ; \
		s|examples tmp|examples/* tmp|' \
		${WRKSRC}/icm_bootstrap \
		${WRKSRC}/icm_install
	@${REINPLACE_CMD} -e 's|"gcc"|"${CC}"|g; s|-Wall -O2|${CFLAGS}|g' \
		${WRKSRC}/doc/icmake.doc \
		${WRKSRC}/exec/icmconf \
		${WRKSRC}/usr/share/icmake/icmconf

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_prepare ${PREFIX}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_bootstrap x

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install strip progs ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install scripts ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install etc ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install man ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install skel ${STAGEDIR}

do-install-DOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install doc ${STAGEDIR}

do-install-EXAMPLES-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install docdoc ${STAGEDIR}

.include <bsd.port.mk>
