# Created by: Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
# $FreeBSD$

PORTNAME=	mh
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	5
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.laic.u-hyogo.ac.jp/pub/net/mh/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${VERSION}-JP-${JP_VERSION}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Rand MH mail handling system + Japanese patches

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: wantcomp
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: wantcomp

BUILD_DEPENDS=	jless:japanese/less
RUN_DEPENDS=	jless:japanese/less

VERSION=	6.8.4
JP_VERSION=	3.05

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-batchmode \
		--enable-apop=${PREFIX}/etc/pop.auth \
		--enable-jmandir=${MANPREFIX}/man/ja
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-Wno-return-type
LLD_UNSAFE=	yes

USE_LDCONFIG=	yes

PORTDOCS=	00.READ.ME.1ST CHANGES.JP COMMANDS.JP FAQ.JP FEATURES.JP \
		INSTALL.JP OPTIONS.JP READ-ME.JP TODO.JP
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

CONFLICTS=	nmh-[0-9]*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s/-O /${CFLAGS} /g" ${WRKSRC}/configure
.for i in comp dist forw mh-mail mhl ja-comp ja-dist ja-forw ja-mh-mail ja-mhl
	@(cd ${WRKSRC}/conf/doc && \
	${AWK} '{ \
	if (/^\.so/) { \
		ifile="../../support/general" substr($$2, index($$2, "/")); \
		while((getline l < ifile > 0)) \
			print l; \
		close(ifile); \
	} else \
		print; \
	}' ${i}.rf > ${i}.tmp && ${MV} ${i}.tmp ${i}.rf)
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmh.so.3
.for i in ap conflict dp fmtdump install-mh mhl post rcvdist rcvpack rcvstore rcvtty slocal spost
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mh/${i}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc-JP && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
