# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	filters
PORTVERSION=	2.55
DISTVERSIONSUFFIX=	.orig
CATEGORIES=	games perl5
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Collection of filters, including B1FF, and the Swedish Chef

LICENSE=	GPLv2

CONFLICTS=	talkfilters-[0-9]* jive-[0-9]* chef-[0-9]* kenny-[0-9]*

USES=		gmake perl5 shebangfix

WRKSRC=		${WRKDIR}/${PORTNAME}

PERLFILTERS=	b1ff censor chef eleet fudd jibberish kenny pirate rasterman \
		spammer studly uniencode upside-down fanboy scottish LOLCAT
CFILTERS=	jethro kraut cockney jive nyc ken ky00te newspeak nethackify \
		scramble

SHEBANG_FILES=	${PERLFILTERS}

post-extract:
	@${MV} ${WRKSRC}/${PORTNAME}.6 ${WRKSRC}/${PORTNAME}.1

do-install:
.for f in ${CFILTERS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in ${PERLFILTERS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
