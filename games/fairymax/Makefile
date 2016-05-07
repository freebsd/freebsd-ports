# Created by: Kalten <kalten@gmx.at>
# $FreeBSD$

PORTNAME=	fairymax
PORTVERSION=	5.0b.20160316.1
CATEGORIES=	games
MASTER_SITES=	http://freeheimdall.spdns.org/files/
# http://hgm.nubati.net/cgi-bin/gitweb.cgi?p=fairymax.git;a=snapshot;h=${COMMIT_HASH};sf=tgz
# http://hgm.nubati.net/cgi-bin/gitweb.cgi/fairymax.git/snapshot/${COMMIT_HASH}
# but sha256 changes, as creation date of *.tar inside *.tar.gz changes.
DISTNAME=	${PORTNAME}-${COMMIT_HASH}

MAINTAINER=	kalten@gmx.at
COMMENT=	Chess engine for shatranj, courier chess, and others

COMMIT_HASH=	67cee03

OPTIONS_DEFINE=	DOCS

PORTDOCS=	changelog copyright CVfairy.html README

USES=		gmake perl5
USE_PERL5=	build
MAKE_ARGS+=	prefix= \
		bindir=${PREFIX}/bin \
		mandir=${PREFIX}/man \
		datadir= \
		plugindir=${PREFIX}/share/games/plugins \
		fairydir=${DATADIR} \
		VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -E 's|(#define VERSION ")[^"]+(".*)|\1${PORTVERSION}\2|' \
		${WRKSRC}/fairymax.c
	@${REINPLACE_CMD} -E 's|^(prefix\|bindir\|mandir\|datadir\|plugindir\|fairydir) =|\1 ?=|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E 's|^	cp (.{srcdir}/fairymax .{srcdir}/shamax .{srcdir}/maxqi .\(DESTDIR\).\(bindir\))|	${INSTALL_PROGRAM} \1|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E 's|^	cp (.{srcdir}/data/)|	${INSTALL_DATA} \1|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E 's|^	cp (.{srcdir}/fairymax.6.gz)|	${INSTALL_MAN} \1|' \
		${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
