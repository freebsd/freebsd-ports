/*******************************************************************************
 * Copyright (c) 2020 Red Hat Inc.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Red Hat Inc. - initial version
 *******************************************************************************/
package org.eclipse.equinox.internal.security.linux;

public class SecretCollectionFlags {
	public final static int SECRET_COLLECTION_NONE = 0 << 0;
	public final static int SECRET_COLLECTION_LOAD_ITEMS = 1 << 1;
}
