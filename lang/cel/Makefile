# New ports collection makefile for:   cel
# Date created:        1 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cel
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	# none
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small, simple prototype-based OO language

DEPRECATED=	"probable abandonware: mastersite disappeared Jan 2004\; only works on i386"
EXPIRATION_DATE=	"May 5, 2004"

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_REINPLACE=	yes

PORTDOCS=	CoreArchitecture.html DefaultProtos Linker.html \
		Logs.html ProtoLanguage.html README SimpleDataFormat.html \
		Threads activation.html stackframe structure.html todo.html
PLIST_FILES=	bin/cel

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-fno-omit-frame-pointer,${CFLAGS}," \
		${WRKSRC}/hash/Makefile ${WRKSRC}/kits/Makefile.unix \
		${WRKSRC}/vm/Makefile.unix

do-configure:
	@cd ${WRKSRC}; ${SH} ./config.unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vm/cel ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cel
.for F in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/$F ${PREFIX}/share/doc/cel
.endfor
.endif

.include <bsd.port.post.mk>
