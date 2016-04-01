# Created by: pgl@instinct.org
# $FreeBSD$

PORTNAME=	pisg
PORTVERSION=	0.73
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl IRC Statistics Generator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
SHEBANG_FILES=	pisg
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	LOGCHARSET DOCS
LOGCHARSET_DESC=	Character set for logfiles
LOGCHARSET_RUN_DEPENDS=	p5-Text-Iconv>=0:converters/p5-Text-Iconv

pre-patch:
	@${REINPLACE_CMD} -e 's|lang.txt|${PREFIX}/share/pisg/lang.txt|; \
		s|layout/|${PREFIX}/share/pisg/layout/|' \
		${WRKSRC}/modules/Pisg.pm

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pisg
	@${MKDIR} ${STAGEDIR}${DATADIR}/layout
	@${MKDIR} ${STAGEDIR}${DATADIR}/gfx
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Pisg/Parser/Format
	${INSTALL_DATA} ${WRKSRC}/pisg.cfg ${STAGEDIR}${PREFIX}/etc/pisg/pisg.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/gfx/* ${STAGEDIR}${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/layout/* ${STAGEDIR}${DATADIR}/layout
	${INSTALL_DATA} ${WRKSRC}/lang.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Pisg
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/Parser/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Pisg/Parser
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/Parser/Format/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Pisg/Parser/Format
	${INSTALL_SCRIPT} ${WRKSRC}/pisg ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/pisg-doc.txt ${STAGEDIR}${DOCSDIR}/pisg-doc.txt

.include <bsd.port.mk>
