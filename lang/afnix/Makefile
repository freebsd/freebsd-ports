# ex:ts=8
# New ports collection makefile for:	aleph
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	afnix
PORTVERSION=	1.8.0
CATEGORIES=	lang
MASTER_SITES=	http://www.afnix.org/ftp/ \
		ftp://ftp.stack.nl/pub/users/johans/afnix/
MASTER_SITE_SUBDIR=	${PORTNAME}-${AFNIX_VERSION}
DISTNAME=	${PORTNAME}-src-${AFNIX_VERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@stack.nl
COMMENT=	A multi-threaded functional programming language

USE_GMAKE=	yes
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	cnf/bin/afnix-setup
CONFIGURE_ARGS=		-o --prefix "${PREFIX}" --altdir "${PREFIX}" \
			--shrdir "${PREFIX}/share" --compiler freebsd
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PORTDOCS=	*
AFNIX_VERSION=	${PORTVERSION:S,.,-,g}
PLIST_SUB=	PORTVER=${PORTVERSION:R}

MAN1=	adp::afnix.1 amd::afnix.1 axc::afnix.1 axd::afnix.1 \
	axi::afnix.1 axl::afnix.1 axs::afnix.1
MAN3=	gfx::afnix.3 mth::afnix.3 net::afnix.3 nwg::afnix.3 \
	pim::afnix.3 sec::afnix.3 sio::afnix.3 sps::afnix.3 \
	sys::afnix.3 txt::afnix.3 xml::afnix.3
MAN4=	wax::afnix.4 xpe::afnix.4
MAN7=	eul::afnix.7 vol-0::afnix.7 vol-1::afnix.7 vol-2::afnix.7

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC}/cnf/mak && ${CP} -f afnix-gcc-3.mak afnix-freebsd.mak

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CP)|$$(BSD_INSTALL_PROGRAM)|' \
		${WRKSRC}/src/*/*/exe/Makefile
	@${REINPLACE_CMD} -e '/\.rtf/d' ${WRKSRC}/etc/Makefile
	@${REINPLACE_CMD} -e '/^MANDIR/s/SHRDIR/MANPREFIX/' \
		${WRKSRC}/cnf/mak/afnix-defs.mak
	@${REINPLACE_CMD} -e '/uname -r/s/\\\./[.-]/' \
		${WRKSRC}/cnf/bin/afnix-guess

post-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} doc
	@cd ${WRKSRC}/prj && ${SETENV} ${MAKE_ENV} ${GMAKE} doc

post-install:
.ifdef	NOPORTDOCS
. for i in ${MAN1} ${MAN3} ${MAN4} ${MAN7}
	${INSTALL_MAN} ${WRKSRC}/bld/${PORTNAME}-doc-${AFNIX_VERSION}/man/$i \
		${MANPREFIX}/man/man${i:E}/
. endfor
.else
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} instdoc
.endif

.include <bsd.port.post.mk>
