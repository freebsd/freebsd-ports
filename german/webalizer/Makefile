# New ports collection makefile for:	webalizer
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	webalizer
PORTVERSION=	1.30.4
PORTREVISION=	1
CATEGORIES=	german www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://ftp.lan-ks.de/pub/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-1.30-04-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirk.meyer@dinoex.sub.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

WEBALIZER_LANG?=	german
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gdlib=${PREFIX}/lib \
			--with-gd=${PREFIX}/include/gd \
			--with-language=${WEBALIZER_LANG}
CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"
BIN1=		de-webalizer
MAN1=		de-webalizer.1
DOC1=		CHANGES COPYING Copyright INSTALL \
		README country-codes.txt webalizer.LSM
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src$//}

pre-configure:
	@${PERL5} -pi -e "s=/etc=${PREFIX}/etc=" ${WRKSRC}/webalizer.c

do-install:
.for i in ${BIN1}
	@${INSTALL_SCRIPT} ${WRKSRC}/webalizer ${PREFIX}/bin/${i}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/webalizer.1 ${PREFIX}/man/man1/de-webalizer.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/de-webalizer
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/de-webalizer/${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/de-webalizer
.for i in msfree.gif sample.conf webalizer.gif
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/de-webalizer/${i}
.endfor
	@if [ ! -f ${PREFIX}/etc/de-webalizer.conf-dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.conf \
			${PREFIX}/etc/de-webalizer.conf-dist ; \
	fi

.include <bsd.port.mk>
