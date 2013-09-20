# Created by: Jun-ichiro itojun Itoh <itojun@itojun.org>
# $FreeBSD$

PORTNAME=	nvi
PORTVERSION=	1.79.20040608
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	ftp://ftp.mk.bsdclub.org/pub/FreeBSD/distfiles/	\
		http://people.allbsd.org/~hrs/FreeBSD/
PKGNAMESUFFIX?=	-m17n
DISTNAME=	nvi-1.79

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	nvi-m17n-1.79-20040608.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of vi/ex, with multilingual patch, no default settings

PATCH_DIST_ARGS=	-d ${WRKSRC}/.. --forward --quiet -E -p0 -f
WRKSRC=		${WRKDIR}/${DISTNAME}/build

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPTFLAG='-D_PATH_SYSEXRC=\"${PREFIX}/etc/vi.exrc\"'
CONFIGURE_ARGS=	--enable-multibyte --program-prefix=n

MAN1=		nvi.1
MLINKS=		nvi.1 nex.1  nvi.1 nview.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	${LN} -s /usr/include/sys/queue.h ${WRKSRC}/../include/sys/queue_dist.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/../docs.m17n/README.english \
		${PREFIX}/share/vi/
	${INSTALL_DATA} ${WRKSRC}/../docs.m17n/README.japanese \
		 ${PREFIX}/share/vi/

.include <bsd.port.post.mk>
