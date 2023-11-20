/*
 * OpenSSL no longer offers the "-C" option for its dhparam
 * subcommand, so we keep our own C-code here...
 */

static DH * get_dhParams(void) {
	static unsigned char dhp_2048[] = {
#include "generateddh.txt"
	};
	static unsigned char dhg_2048[] = {
		0x02
	};
	DH	       *dh = DH_new();
	BIGNUM	       *p, *g;

	if (dh == NULL)
		return NULL;
	p = BN_bin2bn(dhp_2048, sizeof(dhp_2048), NULL);
	g = BN_bin2bn(dhg_2048, sizeof(dhg_2048), NULL);
	if (p == NULL || g == NULL
	    || !DH_set0_pqg(dh, p, NULL, g)) {
		DH_free(dh);
		BN_free(p);
		BN_free(g);
		return NULL;
	}
	return dh;
}
