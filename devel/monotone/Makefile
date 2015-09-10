# Created by: Mark A. Wicks <mwicks@kettering.edu>
# $FreeBSD$

PORTNAME=	monotone
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.monotone.ca/downloads/${PORTVERSION}/

MAINTAINER=	lapo@lapo.it
COMMENT=	Distributed version control system with digital signatures

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libidn.so:${PORTSDIR}/dns/libidn \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libbotan-1.10.so:${PORTSDIR}/security/botan110

SUB_FILES=	pkg-message
USES=		cpe iconv pkgconfig gmake perl5 lua:51 tar:bzip2 makeinfo
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mtn bin/mtn-cleanup bin/mtnopt \
		share/monotone/hooks/authorize_remote_automate.lua \
		share/monotone/hooks/get_passphrase_from_file.lua \
		share/monotone/hooks/monotone-buildbot.lua \
		share/monotone/hooks/monotone-ciabot.lua \
		share/monotone/hooks/monotone-cluster-push.lua \
		share/monotone/hooks/monotone-cvs-ignore.lua \
		share/monotone/hooks/monotone-mail-notify.lua \
		share/monotone/scripts/monotone-ciabot.py \
		share/monotone/scripts/monotone-mail-notify \
		etc/bash_completion.d/monotone.bash_completion \
		share/zsh/site-functions/_mtn \
		"@unexec [ -f %D/bin/zsh ] || ${RMDIR} %D/share/zsh/site-functions 2>/dev/null || true" \
		"@dirrmtry share/zsh" \
		"@dirrmtry etc/bash_completion.d" \
		"@dirrm share/monotone/hooks" \
		"@dirrmtry share/zsh/site-functions" \
		"@dirrm share/monotone/scripts" \
		"@dirrm share/monotone"
INFO=		monotone
PLIST_FILES+=	man/man1/mtn.1.gz \
		man/man1/mtn-cleanup.1.gz \
		man/man1/mtnopt.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_FILES+=	share/locale/de/LC_MESSAGES/monotone.mo \
		share/locale/fr/LC_MESSAGES/monotone.mo \
		share/locale/it/LC_MESSAGES/monotone.mo \
		share/locale/pt/LC_MESSAGES/monotone.mo \
		share/locale/sv/LC_MESSAGES/monotone.mo
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

post-extract:
	@${RM} -f ${WRKSRC}/monotone.info*

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -Ee '/^install-(contrib|examples)-data:/{' -e 'n' -e 'd' -e '}' ${WRKSRC}/Makefile.in
.endif
	${REINPLACE_CMD} \
		-e "s/REBUILD_NLS=true/REBUILD_NLS=false/g" \
		-e "s/std::tr1::/std::/g" \
		${WRKSRC}/configure
	${REINPLACE_CMD} \
		-e "s/std::tr1::/std::/g" \
		${WRKSRC}/src/hash_map.hh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/monotone.zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_mtn
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} NEWS UPGRADE ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
