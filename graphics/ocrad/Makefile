# New ports collection makefile for:	graphics/ocrad
# Date created:				12.11.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	ocrad
PORTVERSION=	0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	q@uni.de
COMMENT=	OCR program implemented as filter

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

DOCS=		AUTHORS ChangeLog NEWS README TODO
INFO=		ocrad
MAN1=		ocrad.1

STD_PATCH=	textline.cc recognize2.cc bitmap.cc main.cc

.include <bsd.port.pre.mk>
post-patch:
.if ${OSVERSION} < 500000
.for file in ${STD_PATCH}
	@${REINPLACE_CMD} -e 's/std::isspace/isspace/g; s/std::getc/getc/g' \
		-e 's/std::ungetc/ungetc/g; s/std::feof/feof/g' \
		-e 's/std::ferror/ferror/g' ${WRKSRC}/${file}
.endfor
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@${INSTALL_MAN} ${FILESDIR}/ocrad.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
