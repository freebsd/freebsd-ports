# New ports collection makefile for:	webalizer2
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	webalizer
PORTVERSION=	2.1.6
PORTREVISION=	2
CATEGORIES=	german www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
PKGNAMEPREFIX?=	de-
DISTNAME=	${PORTNAME}-2.01-06-src

MAINTAINER=	dirk.meyer@dinoex.sub.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
WEBALIZER_LANG?=	german

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--enable-dns \
			--with-etcdir=${PREFIX}/etc \
			--with-gdlib=${PREFIX}/lib \
			--with-gd=${PREFIX}/include/gd \
			--with-language=${WEBALIZER_LANG}
CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"
MAKE_ARGS+=	CFLAGS="${CFLAGS}"
MAN1=		${PKGNAMEPREFIX}webalizer.1
DOC1=		CHANGES COPYING Copyright INSTALL \
		README README.FIRST DNS.README country-codes.txt
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src$//}
PLIST_SUB+=	PKGNAMEPREFIX=${PKGNAMEPREFIX}

pre-configure:
	@${PERL5} -pi -e "s=/etc=${PREFIX}/etc=" ${WRKSRC}/webalizer.1
	@${PERL5} -pi -e "s=webalizer.conf=${PKGNAMEPREFIX}webalizer.conf=" \
		${WRKSRC}/webalizer.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webalizer
	${LN} -sf ${PKGNAMEPREFIX}webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webazolver

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/webalizer.1 ${PREFIX}/man/man1/${i}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PKGNAMEPREFIX}webalizer
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} \
		${PREFIX}/share/doc/${PKGNAMEPREFIX}webalizer/${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/${PKGNAMEPREFIX}webalizer
.for i in msfree.png sample.conf webalizer.png
	@${INSTALL_DATA} ${WRKSRC}/${i} \
		${PREFIX}/share/examples/${PKGNAMEPREFIX}webalizer/${i}
.endfor
	@if [ ! -f ${PREFIX}/etc/${PKGNAMEPREFIX}webalizer.conf-dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.conf \
			${PREFIX}/etc/${PKGNAMEPREFIX}webalizer.conf-dist ; \
	fi

.include <bsd.port.post.mk>
