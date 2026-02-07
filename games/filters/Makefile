PORTNAME=	filters
DISTVERSION=	2.56
DISTVERSIONSUFFIX=	.orig
CATEGORIES=	games perl5
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Collection of filters, including B1FF, and the Swedish Chef
WWW=		https://joeyh.name/code/filters/

LICENSE=	GPLv2

USES=		gmake perl5 shebangfix tar:xz

SHEBANG_FILES=	${PERLFILTERS}

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	chef kenny lolcat talkfilters

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PERLFILTERS=	b1ff censor chef eleet fudd jibberish kenny pirate rasterman \
		spammer studly uniencode upside-down fanboy scottish LOLCAT
CFILTERS=	jethro kraut cockney jive nyc ken ky00te newspeak nethackify \
		scramble

post-extract:
	@${MV} ${WRKSRC}/${PORTNAME}.6 ${WRKSRC}/${PORTNAME}.1

do-install:
.for f in ${CFILTERS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in ${PERLFILTERS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
