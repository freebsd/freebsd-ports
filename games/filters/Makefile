# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	filters
PORTVERSION=	2.49
CATEGORIES=	games perl5
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/f/filters/ \
		CRITICAL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Collection of filters, including B1FF, and the Swedish Chef

CONFLICTS=	talkfilters-[0-9]* jive-[0-9]* chef-[0-9]* kenny-[0-9]* \
		lolcat-[0-9]*

USES=		shebangfix gmake
USE_PERL5=	yes
USE_GCC=	any
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PERLFILTERS=	b1ff censor chef eleet fudd jibberish kenny pirate rasterman \
		spammer studly uniencode upside-down fanboy scottish lolcat
CFILTERS=	jethro kraut cockney jive nyc ken ky00te newspeak nethackify \
		scramble

SHEBANG_FILES=	${PERLFILTERS}

MAN1=		filters.1
MLINKS=	filters.1 b1ff.1 \
		filters.1 censor.1 \
		filters.1 chef.1 \
		filters.1 eleet.1 \
		filters.1 fudd.1 \
		filters.1 jibberish.1 \
		filters.1 kenny.1 \
		filters.1 pirate.1 \
		filters.1 rasterman.1 \
		filters.1 spammer.1 \
		filters.1 studly.1 \
		filters.1 uniencode.1 \
		filters.1 upside-down.1 \
		filters.1 jethro.1 \
		filters.1 kraut.1 \
		filters.1 cockney.1 \
		filters.1 jive.1 \
		filters.1 nyc.1 \
		filters.1 ken.1 \
		filters.1 ky00te.1 \
		filters.1 newspeak.1 \
		filters.1 nethackify.1 \
		filters.1 fanboy.1 \
		filters.1 scottish.1 \
		filters.1 scramble.1

post-extract:
	@${MV} ${WRKSRC}/${PORTNAME}.6 ${WRKSRC}/${MAN1}

do-install:
.for f in ${CFILTERS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for f in ${PERLFILTERS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
