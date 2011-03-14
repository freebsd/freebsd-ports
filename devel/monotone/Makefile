# New ports collection makefile for:   monotone
# Date created:                05 Feb 2004
# Whom:                        Mark A. Wicks <mwicks@kettering.edu>
#
# $FreeBSD$
#

PORTNAME=	monotone
PORTVERSION=	0.99.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.monotone.ca/downloads/${PORTVERSION}/

MAINTAINER=	lapo@lapo.it
COMMENT=	A distributed version control system with digital signatures

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		idn.17:${PORTSDIR}/dns/libidn \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		botan.0:${PORTSDIR}/security/botan

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

SUB_FILES=	pkg-message
USE_PERL5_BUILD=yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_LUA=	5.1+

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"

PLIST_FILES=	bin/mtn bin/mtnopt share/zsh/site-functions/_mtn \
		"@unexec [ -f %D/bin/zsh ] || ${RMDIR} %D/share/zsh/site-functions 2>/dev/null || true" \
		"@dirrmtry share/zsh"
.if !defined(NO_INSTALL_MANPAGES)
INFO=		monotone
MAN1=		mtn.1
.endif
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
USE_GCC=	4.2+
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.else
USE_GETTEXT=	yes
PLIST_FILES+=	share/locale/de/LC_MESSAGES/monotone.mo \
		share/locale/es/LC_MESSAGES/monotone.mo \
		share/locale/it/LC_MESSAGES/monotone.mo \
		share/locale/pt/LC_MESSAGES/monotone.mo \
		share/locale/sv/LC_MESSAGES/monotone.mo
.endif

post-extract:
	@${RM} -f ${WRKSRC}/monotone.info*

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -Ee '/^install-data-am:/,/^$$/s/install-html(figure|image)?DATA //g' ${WRKSRC}/Makefile.in
.endif
.if defined(NO_INSTALL_MANPAGES)
	${REINPLACE_CMD} -Ee '/^install-data-am:/,/^$$/s/([[:space:]]*)install-(info-am|man)/\1/' ${WRKSRC}/Makefile.in
.endif

post-install:
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/monotone.zsh_completion ${PREFIX}/share/zsh/site-functions/_mtn
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} NEWS UPGRADE ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
