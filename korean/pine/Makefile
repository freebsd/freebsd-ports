# New ports collection makefile for:	pine-ko
#
# Version required:     3.96k2
# Date created:		15 Mar 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# k3 means pico hangul patch
#
# $Id: Makefile,v 1.8 1998/10/16 03:03:08 jseger Exp $
#

DISTNAME=       pine3.96
PKGNAME=        ko-pine-3.96k.3
CATEGORIES=     korean mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/old/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/incoming/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/incoming/
DISTFILES=	pine3.96.tar.Z pine396k2.tar.gz

PATCH_SITES=	ftp://jazz.snu.ac.kr/pub/unix/util/misc/
PATCHFILES=	pico-3.96-hangul.patch

MAINTAINER=	junker@jazz.snu.ac.kr

BROKEN_ELF=	yes

MAKE_ENV=	FILESDIR=${FILESDIR}
MAN1= 		pine.1 pico.1 pilot.1

post-patch:
	@cd ${WRKSRC} && \
	${PATCH} -s -p1 < ${WRKDIR}/pine396k2/pine396k2.patch
	@cd ${WRKDIR} && \
	${PATCH} -s < ${FILESDIR}/dot.pinerc.ko.sample.patch

post-install:
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/pine
	cd ${WRKSRC} && \
		${INSTALL_DATA} doc/tech-notes.txt ${PREFIX}/share/doc/pine
		${INSTALL_DATA} ${WRKDIR}/pine396k2/README \
		${PREFIX}/share/doc/pine/README.patch.ko
		${INSTALL_DATA} ${WRKDIR}/pine396k2/pine.doc \
		${PREFIX}/share/doc/pine/README.pine.ko
		${INSTALL_DATA} ${WRKDIR}/pine396k2/pinerc.sample \
		${PREFIX}/etc/dot.pinerc.ko.sample

.include <bsd.port.mk>
