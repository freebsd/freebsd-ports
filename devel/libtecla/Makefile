PORTNAME=	libtecla
PORTVERSION=	1.6.3
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	k@stereochro.me
COMMENT=	Interactive command line editing facilities
WWW=		https://www.astro.caltech.edu/~mcs/tecla/

LICENSE=	MIT

USE_LDCONFIG=	yes
USE_SUBMAKE=	yes

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	default

LLD_UNSAFE=	yes
SSP_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^OPT = -O,OPT =,' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/enhance ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libtecla.h ${STAGEDIR}${PREFIX}/include
.for l in libtecla libtecla_r
	${INSTALL_LIB} ${WRKSRC}/${l}.so.1 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${l}.a ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf ${l}.so.1 ${l}.so)
.endfor
	for n in ${WRKSRC}/man/prog/*.in; do \
		d=$${n##*/}; \
		${INSTALL_MAN} $${n%.in} ${STAGEDIR}${PREFIX}/man/man1/$${d%.in}.1; \
	done
	for n in ${WRKSRC}/man/libr/*.in ${WRKSRC}/man/func/*.in; do \
		d=$${n##*/}; \
		${INSTALL_MAN} $${n%.in} ${STAGEDIR}${PREFIX}/man/man3/$${d%.in}.3; \
	done
	for n in ${WRKSRC}/man/file/*.in; do \
		d=$${n##*/}; \
		${INSTALL_MAN} $${n%.in} ${STAGEDIR}${PREFIX}/man/man5/$${d%.in}.5; \
	done
	for n in ${WRKSRC}/man/misc/*.in; do \
		d=$${n##*/}; \
		${INSTALL_MAN} $${n%.in} ${STAGEDIR}${PREFIX}/man/man7/$${d%.in}.7; \
	done

.include <bsd.port.post.mk>
