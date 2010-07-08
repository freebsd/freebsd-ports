# New ports collection makefile for:	paexec
# Date created:				2008/01/26
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	paexec
PORTVERSION=	0.14.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Parallel executor, distributes tasks over network

LIB_DEPENDS=	maa:${PORTSDIR}/devel/libmaa

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		ChangeLog NEWS README
MAN1=		paexec.1

LICENSE=	MIT

post-patch:
	@${REINPLACE_CMD} -e 's,2048,4096,; s,x.y.z,${PORTVERSION},' \
		${WRKSRC}/paexec.c

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} \
		*.c -o ${PORTNAME} -lmaa

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/paexec ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/paexec.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
