# New ports collection makefile for:   monotone
# Date created:                05 Feb 2004
# Whom:                        Mark A. Wicks <mwicks@kettering.edu>
#
# $FreeBSD$
#

PORTNAME=	monotone
PORTVERSION=	0.39
CATEGORIES=	devel
MASTER_SITES=	http://monotone.ca/downloads/${PORTVERSION}/

MAINTAINER=	lapo@lapo.it
COMMENT=	A distributed version control system with digital signatures

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

SUB_FILES=	pkg-message
USE_PERL5_BUILD=yes
USE_ICONV=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS+=	--with-system-pcre

PLIST_FILES=	bin/mtn share/zsh/site-functions/_mtn \
		"@unexec [ -f %D/bin/zsh ] || rmdir %D/share/zsh/site-functions 2>/dev/null || true" \
		"@dirrmtry share/zsh"
INFO=		monotone
PORTDOCS=	NEWS UPGRADE monotone.html

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.else
USE_GETTEXT=	yes
PLIST_FILES+=	share/locale/de/LC_MESSAGES/monotone.mo \
		share/locale/es/LC_MESSAGES/monotone.mo \
		share/locale/fr/LC_MESSAGES/monotone.mo \
		share/locale/it/LC_MESSAGES/monotone.mo \
		share/locale/ja/LC_MESSAGES/monotone.mo \
		share/locale/pt_BR/LC_MESSAGES/monotone.mo \
		share/locale/sv/LC_MESSAGES/monotone.mo
.endif

post-extract:
	@${RM} -f ${WRKSRC}/monotone.info*

post-install:
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/monotone.zsh_completion ${PREFIX}/share/zsh/site-functions/_mtn
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
