# $FreeBSD$

PORTNAME=	cbview
PORTVERSION=	0.06
PORTREVISION=	8
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sourcefiles.org/Toys/Humor/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Viewer/converter for CBR/CBZ comic book archives

LICENSE=	GPLv2

RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-String-ShellQuote>=0:${PORTSDIR}/textproc/p5-String-ShellQuote

NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	Changes README TODO

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl -w|${PERL}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
