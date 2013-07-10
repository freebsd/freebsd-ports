# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elk
PORTVERSION=	3.99.8
CATEGORIES=	lang scheme
MASTER_SITES=	http://sam.zoy.org/elk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embeddable Scheme interpreter

LIB_DEPENDS=	gdbm.4:${PORTSDIR}/databases/gdbm \
		elf.0:${PORTSDIR}/devel/libelf

USES=		motif
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		elk.1

CPPFLAGS+=	-I${LOCALBASE}/include/libelf -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS=		-O0
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc examples||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/elk.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/examples --exclude "*Makefile*" -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREMODE}:${SHAREGRP} ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR}/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;
.endif

.include <bsd.port.post.mk>
