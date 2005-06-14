# New ports collection makefile for:	cbview
# Date created:				05 May 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cbview
PORTVERSION=	0.06
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	http://elvine.org/code/cbview/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A viewer/converter for CBR/CBZ comic book archives

RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	COPYING Changes INSTALL README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|perl -w|env perl|g' \
		${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
