# New ports collection makefile for:	filters
# Date created:				7 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	filters
PORTVERSION=	2.34
CATEGORIES=	games perl5
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/f/filters/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A collection of filters, including B1FF and the Swedish Chef

CONFLICTS=	talkfilters-* jive-* chef-*

USE_PERL5=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

ALL_TARGET+=	samples
CFLAGS+=	-lfl

WRKSRC=		${WRKDIR}/${PORTNAME}
PERLFILTERS=	b1ff censor chef eleet fudd jibberish rasterman \
		spammer studly uniencode upside-down
CFILTERS=	jethro kraut cockney jive nyc ken ky00te newspeak
MAN6=		filters.6

.include <bsd.port.pre.mk>

EXTRACFLAGS!=	${ECHO} ${CFLAGS} | ${SED} -e 's|\-lfl||'

post-patch:
.for f in ${FILTERS}
	@${REINPLACE_CMD} -e 's|/usr/local/bin/perl|${PERL}|' \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|^\(CFLAGS\).*=|\1?=|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/doc/filters|${EXAMPLESDIR}|' \
		${WRKSRC}/${MAN6}
	@${REINPLACE_CMD} \
		-e 's|\([[:space:]]\)cc\ |\1${CC}\ |' \
		-e 's|..CFLAGS.\(\ -o\ \.\{2\}\)|${EXTRACFLAGS}\1|' \
			${WRKSRC}/ky00te.dir/makefile

do-install:
.for f in ${PERLFILTERS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for f in ${CFILTERS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${MANPREFIX}/man/man6
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/SAMPLES ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
