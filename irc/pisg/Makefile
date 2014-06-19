# Created by: pgl@instinct.org
# $FreeBSD$

PORTNAME=	pisg
PORTVERSION=	0.73
CATEGORIES=	irc
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Perl IRC Statistics Generator

USES=		perl5
NO_BUILD=	YES

OPTIONS_DEFINE=	LOGCHARSET DOCS
LOGCHARSET_DESC=	Character set for logfiles

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOGCHARSET}
RUN_DEPENDS+=	p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv
.endif

do-build:

pre-patch:
	@${REINPLACE_CMD} -e 's|lang.txt|${PREFIX}/share/pisg/lang.txt|; \
		s|layout/|${PREFIX}/share/pisg/layout/|' \
		${WRKSRC}/modules/Pisg.pm
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/pisg

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pisg
	${MKDIR} ${STAGEDIR}${DATADIR}/layout
	${MKDIR} ${STAGEDIR}${DATADIR}/gfx
	${MKDIR} ${STAGEDIR}${SITE_PERL}/Pisg/Parser/Format
	${INSTALL_DATA} ${WRKSRC}/pisg.cfg ${STAGEDIR}${PREFIX}/etc/pisg/pisg.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/gfx/* ${STAGEDIR}${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/layout/* ${STAGEDIR}${DATADIR}/layout
	${INSTALL_DATA} ${WRKSRC}/lang.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg.pm ${STAGEDIR}${SITE_PERL}
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/*.pm ${STAGEDIR}${SITE_PERL}/Pisg
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/Parser/*.pm ${STAGEDIR}${SITE_PERL}/Pisg/Parser
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/Parser/Format/*.pm ${STAGEDIR}${SITE_PERL}/Pisg/Parser/Format
	${INSTALL_SCRIPT} ${WRKSRC}/pisg ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/pisg-doc.txt ${STAGEDIR}${DOCSDIR}/pisg-doc.txt


.include <bsd.port.mk>
