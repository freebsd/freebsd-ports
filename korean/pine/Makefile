# New ports collection makefile for:	pine-3.96k
#
# Version required:     3.96k
# Date created:		2 Apr 1997
# Whom:			Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.3 1997/05/18 07:06:41 asami Exp $
#

DISTNAME=       pine3.96
PKGNAME=        ko-pine-3.96k
CATEGORIES=     korean mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/mail/Others/ \
		ftp://sunsite.kren.nm.kr/pub/packages/hangul/mail/Others/
DISTFILES=      pine3.96.tar.gz pine395k.patch.tar.gz

MAINTAINER=	junker@jazz.snu.ac.kr

EXTRACT_ONLY=   pine3.96.tar.gz
MAN1= 		pine.1 pico.1 pilot.1

post-patch:
	@cd ${WRKSRC}; \
	tar zxf ${DISTDIR}/pine395k.patch.tar.gz; \
	(cd pine395k; \
	 patch < ${FILESDIR}/pine395k.to.396k.patch); \
	patch -s -p0 < pine395k/pine395k.patch

post-install:
	install -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/pine
	cd ${WRKSRC} && \
		${INSTALL_DATA} doc/tech-notes.txt ${PREFIX}/share/doc/pine
	cd ${WRKSRC} && \
		${INSTALL_DATA} pine395k/README \
		${PREFIX}/share/doc/pine/README.patch.ko
	cd ${WRKSRC} && \
		${INSTALL_DATA} pine395k/README.pine \
		${PREFIX}/share/doc/pine/README.pine.ko

.include <bsd.port.mk>
