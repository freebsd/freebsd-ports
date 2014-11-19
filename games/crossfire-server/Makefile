# Created by: Jasper Jongmans <j.jongmans@aprogas.net>
# $FreeBSD$

PORTNAME=	crossfire
PORTVERSION=	1.70.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-server
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}.maps${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for multiplayer graphical arcade and adventure game

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libpng15.so:${PORTSDIR}/graphics/png \
		libsablot.so:${PORTSDIR}/textproc/sablotron

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		gmake libtool perl5 python uidfix
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --with-check=no --localstatedir=/var/games
CONFIGURE_SHELL=${LOCALBASE}/bin/bash
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog DEVELOPERS NEWS README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	PlayerStats README RunTimeCommands SurvivalGuide *.doc *.ps \
		metaserver multigod plugins spellcasters_guide_to_runes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in'| ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl||g'
	@${REINPLACE_CMD} -e 's|^#.*/bin/sh|#! ${LOCALBASE}/bin/bash|g; \
		 s|-ldl||g; \
		 s|python[{].*[}]|${PYTHON_VERSION}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/socket/metaserver.c
	@${REINPLACE_CMD} -e 's| /usr/bin/perl|${LOCALBASE}/bin/perl|' \
		${WRKSRC}/lib/adm/map_expand.pl

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/maps
	@(cd ${WRKDIR}/maps && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/maps)

	@${FIND} ${STAGEDIR}${PREFIX} -exec ${GREP} -q "#!/usr/bin/perl" {} \; \
		-exec ${REINPLACE_CMD} -e \
		's|#!/usr/bin/perl|#!${LOCALBASE}/bin/perl|g' {} \;
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${STAGEDIR}${PREFIX}/bin/crossloop.web
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.bak" -delete

	@${CHMOD} 775 ${STAGEDIR}/var/games/crossfire
	@${CHMOD} 664 ${STAGEDIR}/var/games/crossfire/*
.for d in account datafiles maps players template-maps unique-items
	@${CHMOD} 774 ${STAGEDIR}/var/games/crossfire/${d}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${FIND} ${WRKSRC}/doc -name 'Makefile*' -delete
.for d in playbook playbook-html spoiler spoiler-html
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DOCSDIR2})
.endfor
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
.endif

.include <bsd.port.mk>
