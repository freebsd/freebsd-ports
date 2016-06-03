# Created by: WATANABE junya <junya-w@remus.dti.ne.jp>
# $FreeBSD$

PORTNAME=	mtools
PORTVERSION=	3.9.6
PORTREVISION=	1
CATEGORIES=	japanese emulators
MASTER_SITES=	ftp://ftp.tux.org/pub/knaff/mtools/:mtools  \
		http://mtools.linux.lu/:mtools \
		LOCAL/steve:local PORTS_JP:jp
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:mtools \
		${DISTNAME}.PC98.patch.gz:local,jp
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for manipulating MSDOS files + support 1232KB , Unicode LFN

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		gmake makeinfo
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-xdf
INFO=		mtools

post-patch:
	@cd ${WRKSRC}; \
	  ${GZCAT} ${DISTDIR}/mtools-3.9.6.PC98.patch.gz | ${PATCH} -d . >/dev/null 2>&1; \
	  for f in config.c mtools.5 mtools.texi; do \
	    ${MV} $$f $$f.orig; \
	    ${SED} -e s:/etc/mtools.conf:${PREFIX}/etc/mtools.conf: \
	    < $$f.orig > $$f; done
	@cd ${WRKSRC}/scripts; for f in ocopy xcopy; do \
	 if [ ! -f $$f -a -f $$f.orig ]; then ${CP} -p $$f.orig $$f ; fi \
	 done
	@${REINPLACE_CMD} -E -e 's,MAN(1|5)DIR),DESTDIR)$$(&,' \
		-e '/(INSTALL|LN_S|mkinstalldirs)/ s,(bin|info)dir,DESTDIR)$$(&,g' \
		${WRKSRC}/Makefile.in

post-install:
	@#	mwrite has been removed by author, but we'll keep it just a bit longer
	${LN} -sf ${PREFIX}/bin/mtools ${STAGEDIR}${PREFIX}/bin/mwrite
	${LN} -sf ${PREFIX}/man/man1/mcopy.1.gz \
		${STAGEDIR}${PREFIX}/man/man1/mwrite.1.gz
	${INSTALL_DATA} ${WRKSRC}/mtools.conf ${STAGEDIR}${PREFIX}/etc
	@${ECHO} "Please verify ${PREFIX}/etc/mtools.conf for your machine."

.include <bsd.port.mk>
