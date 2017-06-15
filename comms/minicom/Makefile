# Created by: obrien@cs.ucdavis.edu
# $FreeBSD$

PORTNAME=	minicom
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/3977/ \
		http://alioth.debian.org/frs/download.php/file/3977/ \
		http://fossies.org/linux/misc/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	MS-DOS Telix serial communication program "workalike"

RUN_DEPENDS=	lrz:comms/lrzsz

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

USES=		iconv ncurses
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB} -lncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-dfl-baud=57600 \
			--sysconfdir=${PREFIX}/etc/minicom \
			--enable-lock-dir=/var/spool/lock \
			--enable-dfl-port=/dev/cuau0

post-patch:
	${REINPLACE_CMD} -e "s@/usr/local/bin/@${LOCALBASE}/bin/@; \
		s@/sz@/lsz@;s@/sb@/lsb@;s@/sx@/lsx@;s@/rz@/lrz@; \
		s@/rb@/lrb@;s@/rx@/lrx@" ${WRKSRC}/src/rwconf.c
	${REINPLACE_CMD} -E -e "s@^(SUBDIRS = .*) intl@\1@" \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL} -d -m 0755 ${STAGEDIR}${PREFIX}/etc/minicom
	${INSTALL} -d -o root -g wheel -m 0755 ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}/
	(umask 022 && cd ${WRKSRC} && ${TAR} --exclude '*/Makefile*' \
		 --exclude '*.orig' -chf - extras doc | ${TAR}  -xf - -C \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
