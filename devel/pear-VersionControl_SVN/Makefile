# Ports collection makefile for: pear-VersionControl_SVN
# Date created: 30 Oct 2007
# Whom: Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	VersionControl_SVN
PORTVERSION=	0.3.2
CATEGORIES=	devel pear

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Wrapper interface for the Subversion command-line client

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser

CATEGORY=	VersionControl_SVN
FILES=		SVN.php \
		SVN/Add.php \
		SVN/Blame.php \
		SVN/Cat.php \
		SVN/Checkout.php \
		SVN/Cleanup.php \
		SVN/Commit.php \
		SVN/Copy.php \
		SVN/Delete.php \
		SVN/Diff.php \
		SVN/Export.php \
		SVN/Import.php \
		SVN/Info.php \
		SVN/List.php \
		SVN/Log.php \
		SVN/Merge.php \
		SVN/Mkdir.php \
		SVN/Move.php \
		SVN/Parsers/Log.php \
		SVN/Propdel.php \
		SVN/Propget.php \
		SVN/Proplist.php \
		SVN/Propset.php \
		SVN/Resolved.php \
		SVN/Revert.php \
		SVN/Status.php \
		SVN/Switch.php \
		SVN/Update.php
EXAMPLES=	example1.php \
		example_tree.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
