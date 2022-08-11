PORTNAME=	le
PORTVERSION=	1.16.8
CATEGORIES=	editors
MASTER_SITES=	http://lav.yar.ru/download/${PORTNAME}/ \
		ZI
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Text editor with block and binary operations

LICENSE=	GPLv3

USES=		ncurses perl5 tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAKE_JOBS_UNSAFE=	yes

derp-do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} le ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} le.1 ${STAGEDIR}${MAN1PREFIX}/man/man1)
.for file in ${STAGEDIR}${MISC_DATA}
	(cd ${WRKSRC}/misc && ${INSTALL_DATA} ${file} ${STAGEDIR}${DATADIR})
.endfor
	(cd ${WRKSRC}/misc && ${COPYTREE_SHARE} syntax.d ${STAGEDIR}${DATADIR})
.for file in ${SRC_DATA}
	(cd ${WRKSRC}/src && ${INSTALL_DATA} ${file} ${STAGEDIR}${DATADIR})
.endfor
.for file in FEATURES HISTORY NEWS README TODO
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
