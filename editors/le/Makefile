PORTNAME=	le
PORTVERSION=	1.16.8
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://lav.yar.ru/download/${PORTNAME}/ \
		ZI
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Text editor with block and binary operations
WWW=		https://github.com/lavv17/le

LICENSE=	GPLv3

USES=		localbase ncurses perl5 tar:bzip2
USE_PERL5=	build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name '*.[ch]' -o -name '*.cc' \) | \
		${XARGS} ${GREP} -l '[[:<:]]hex[[:>:]]' | \
		${XARGS} ${REINPLACE_CMD} -e 's/[[:<:]]hex[[:>:]]/is_hex/g'

derp-do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} le ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} le.1 ${STAGEDIR}${PREFIX}/man/man1)
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
