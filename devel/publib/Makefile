# New ports collection makefile for:	publib
# Date created:		25 April 2002
# Whom:			never@nevermind.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	publib
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/p/publib/
DISTNAME=	publib_0.32.orig

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	Publib is a library of C functions for various purposes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/objs
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../framework/configure

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN3=		dynarr.3 \
		xmalloc.3 \
		bitarr.3 \
		cfg.3 \
		cmp.3 \
		__set_liberror.3 \
		errormsg.3 \
		expr.3 \
		files.3 \
		fname.3 \
		fnpathfind.3 \
		fnqualify.3 \
		hash.3 \
		iset.3 \
		log.3 \
		publib.3 \
		stack.3 \
		memarrfill.3 \
		memdel.3 \
		memfill.3 \
		memins.3 \
		memisort.3 \
		memmem.3 \
		memoverlap.3 \
		memrchr.3 \
		memrev.3 \
		memrmem.3 \
		memshuffle.3 \
		memswap.3 \
		stracat.3 \
		stranaxfrm.3 \
		strchange.3 \
		strcins.3 \
		strcstr.3 \
		strdel.3 \
		strdiff.3 \
		strend.3 \
		strendzap.3 \
		strgsub.3 \
		strhash.3 \
		strinit.3 \
		strins.3 \
		strltrim.3 \
		strmaxcpy.3 \
		strmove.3 \
		strmtrim.3 \
		strndup.3 \
		strnins.3 \
		stroverlap.3 \
		strrev.3 \
		strright.3 \
		strrot13.3 \
		strrstr.3 \
		strrtrim.3 \
		strset.3 \
		strshuffle.3 \
		strsplit.3 \
		strsub.3 \
		strtabify.3 \
		strtrexpand.3 \
		strtrim.3 \
		struncstr.3 \
		struntabify.3 \
		strvars.3 \
		strzap.3 \
		tbuf.3

pre-configure::
	${MKDIR} ${WRKSRC}/objs
	${SED} -e "s;@PREFIX@;${PREFIX};g" \
	${FILESDIR}/Default.config > ${WRKSRC}/objs/Default.config

.include <bsd.port.mk>
